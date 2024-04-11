#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

int n,t;
int a[MAX];

void init(void)
{
    cin>>n>>t;
    ff(i,1,n-1) cin>>a[i];
}

void process(void)
{
    int curr=1;
    while(curr<=t)
    {
        curr+=a[curr];
        if(curr==t)
        {
            cout<<"YES";
            return;
        }
        else if(curr>t)
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"NO";
}

int main(void)
{
    init();
    process();
    return 0;
}