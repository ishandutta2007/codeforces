#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Segment tree for range minimum and addition.
class SegTree {
        private:
                const ll NEUT = 4 * (ll)1e18;
                vector<ll> seg, tag;
                int h = 1;

                void apply(int i, ll v) {
                        seg[i] = min(seg[i], v);
                        if (i < h) tag[i] = min(tag[i], v);
                }
                void push(int i) {
                        if (tag[i] == NEUT) return;
                        apply(2*i, tag[i]);
                        apply(2*i+1, tag[i]);
                        tag[i] = NEUT;
                }
                ll combine(ll a, ll b) { return min(a, b); }

                ll recGet(int a, int b, int i, int ia, int ib) {
                        if (ib <= a || b <= ia) return NEUT;
                        if (a <= ia && ib <= b) return seg[i];
                        push(i);
                        int im = (ia + ib) >> 1;
                        return combine(
                                recGet(a, b, 2*i, ia, im),
                                recGet(a, b, 2*i+1, im, ib));
                }
                void recApply(int a, int b, ll v, int i, int ia, int ib) {
                        if (ib <= a || b <= ia) return;
                        if (a <= ia && ib <= b) apply(i, v);
                        else {
                                push(i);
                                int im = (ia + ib) >> 1;
                                recApply(a, b, v, 2*i, ia, im);
                                recApply(a, b, v, 2*i+1, im, ib);
                                seg[i] = combine(seg[2*i], seg[2*i+1]);
                        }
                }
        public:
                SegTree(int n) {
                        while(h < n) h *= 2;
                        seg.resize(2*h, NEUT);
                        tag.resize(h, NEUT);
                }
                ll rangeMin(int a, int b) { return recGet(a, b+1, 1, 0, h); }
                void rangeApply(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	SegTree seg(n+1);
	seg.rangeApply(0, 0, 0);

	string str;
	cin >> str;

	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') {
			ll off = i+1 + seg.rangeMin(i-k, n);
			seg.rangeApply(0, i+k+1, off);
		} else {
			ll off = i+1 + seg.rangeMin(i, i);
			seg.rangeApply(i+1, i+1, off);
		}
	}
	cout << seg.rangeMin(n, n) << '\n';
}