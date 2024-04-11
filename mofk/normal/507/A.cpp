#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

int n,k;vii a;

void init(void)
{
    cin>>n>>k;
    ff(i,1,n)
    {
        int b;
        cin>>b;
        a.pb(mp(b,i));
    }
    sort(a.begin(),a.end());
}

void process(void)
{
    int v=0,cnt=0;vi res;
    while(v<=k&&cnt<n)
    {
        v+=a[cnt].fi;
        res.pb(a[cnt].se);
        cnt++;
    }
    if(v>k) {res.pop_back();cnt--;}
    cout<<cnt<<endl;
    if(cnt) ff(i,0,cnt-1) cout<<res[i]<<" ";
}

int main(void)
{
    init();
    process();
    return 0;
}