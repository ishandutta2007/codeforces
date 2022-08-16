#include<iostream>
#include<vector>

using namespace std;

vector<int> v[5][100010];
int flag[100010];
int pow[10];

int n,ans;
int A[10][10];

void ready()
{
    pow[0]=1;
    for (int i=1;i<=8;++i)
        pow[i]=pow[i-1]*10;
    for (int i=2;i<=99999;++i)
        if (!flag[i])
        {
            for (int j=0;j<5;++j)
                v[j][i/pow[j]*pow[j]].push_back(i);
            for (int j=2;i*j<=99999;++j)
                flag[i*j]=1;
        }
}

void DFS(int k)
{
    int tmp=0;
    for (int i=1;i<k;++i)
        tmp+=(A[k][i]*pow[n-i]);
    if (k==n)
    {
        ans+=v[1][tmp].size();
        return;
    }
    for (vector<int>::iterator it=v[n-k+1][tmp].begin();it!=v[n-k+1][tmp].end();++it)
    {
        for (int i=k;i<=n;++i)
            A[k][i]=A[i][k]=*it/pow[n-i]%10;
        DFS(k+1);
    }
}

int main()
{
    ready();
    int T;
    cin>>T;
    while (T--)
    {
        int p;
        cin>>p;
        int tmp=p;
        n=1;
        while (tmp>=10)
        {
            ++n;
            tmp/=10;
        }
        for (int i=1;i<=n;++i)
            A[1][i]=A[i][1]=p/pow[n-i]%10;
        ans=0;
        DFS(2);
        cout<<ans<<endl;
    }
    return 0;
}