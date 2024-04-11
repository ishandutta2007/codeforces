#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int W, H, N;
set <int> X, Y;
multiset <int> XD, YD;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> W >> H >> N;
    X.insert(0); X.insert(W);
    Y.insert(0); Y.insert(H);
    XD.insert(W); YD.insert(H);
    while (N--){
        char c; int p;
        cin >> c >> p;
        if (c == 'H'){
            auto it = Y.upper_bound(p);
            auto it2 = it;
            it2--;
            YD.erase(YD.find(*it - *it2));
            YD.insert(*it - p);
            YD.insert(p - *it2);
            Y.insert(p);
        }else{
            auto it = X.upper_bound(p);
            auto it2 = it;
            it2--;
            XD.erase(XD.find(*it - *it2));
            XD.insert(*it - p);
            XD.insert(p - *it2);
            X.insert(p);
        }
        int h = *YD.rbegin(), w = *XD.rbegin();
        cout << (lld)h * w << endl;
    }
}