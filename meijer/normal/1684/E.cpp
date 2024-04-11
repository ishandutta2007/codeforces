#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, k, a[N];
int cnt[N];
map<int,int> mp;

int ft[N];
void add(int i, int x) {
    for (i++; i<N; i+=i&-i)
        ft[i] += x;
}
int get(int i) {
    int res=0;
    for (i++; i>0; i-=i&-i)
        res += ft[i];
    return res;
}

int ftCnt[N];
void addCnt(int i, int x) {
    for (i++; i<N; i+=i&-i)
        ftCnt[i] += x;
}
int getCnt(int i) {
    int res=0;
    for (i++; i>0; i-=i&-i)
        res += ftCnt[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cnt[i] = 0;
        for (int i=0; i<n; i++)
            if (a[i] < n)
                cnt[a[i]]++;
        mp.clear();
        for (int i=0; i<n; i++)
            mp[a[i]]++;
        
        for (int i=0; i<n+3; i++)
            ft[i] = ftCnt[i] = 0;
        
        for (auto p : mp) {
            add(p.second, p.second);
            addCnt(p.second, 1);
        }
        
        int ans = 1e9;
        int over = k;
        for (int i=0; i<=n; i++) {
            // mex >= i
            int lb=1, ub=n+1;
            while(lb != ub) {
                int mid=(lb+ub)/2;
                if (get(mid) > k) ub=mid;
                else lb = mid+1;
            }
            if (lb == n+1) {
                ans = 0;
                break;
            } else {
                int removed = getCnt(lb-1);
                removed += (k - get(lb-1)) / lb;
                ans = min<int>(ans, getCnt(n+1) - removed);
            }

            // mex >= i+1
            if (cnt[i] == 0) {
                if (over == 0)
                    break;
                over--;
            } else {
                add(cnt[i], -cnt[i]);
                addCnt(cnt[i], -1);
            }
        }
        cout << ans << endl;
    }
}