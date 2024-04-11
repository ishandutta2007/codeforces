#include <bits/stdc++.h>

using namespace std;
int n, m ,k;
int a[200005];
int g[200005];
pair<int,int> so[200005];
int ma[200005];
bool s(pair<int,int> a, pair<int,int> b){
    if(a.first <= b.first)
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i;
    cin >> n >> m >> k;

    for(i = 0; i< n; i++){
        cin >> a[i];
        so[i] = {a[i],i};
    }
    sort(so, so+n,s);
    int l=0;
    for(i=0;i<n;i++) {
        g[i]=so[i].first;
        if(so[i].first!=so[i-1].first) so[i-1].first=l++;
        else so[i-1].first=l;
    }
    so[n-1].first=l;
    for(int i=0;i<n;i++) a[so[i].second]=so[i].first;
    long long r = 0;
    for(i = 0; i < m*k; i++){
        r = r + g[i];
        ma[so[i].first]++;
    }
    cout << r << endl;
    long long t = 0;
    r = 0;
    for(i = 0; i < n; i++){
        if(t == m){
            cout << i << " ";
            t = 0;
            r++;
            if(r == k - 1)
                break;
        }
        if(ma[a[i]]){
            t++;
            ma[a[i]]--;
        }
    }
    return 0;
}