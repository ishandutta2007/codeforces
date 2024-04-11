#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 110;
int a[N],k[N],cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>k[i];


    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            memset(cnt,0,sizeof(cnt));
            for(int p=i;p<=j;p++){
                cnt[a[p]]++;
            }
            bool ok=true;
            for(int p=1;p<=m;p++){
                if(cnt[p]!=k[p])ok=false;
            }
            if(ok){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}