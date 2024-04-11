#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int bigN = 1e7+10;
int n,i,j,k;
int a[N],ori[N];
int b[N],c[N];
int primo[bigN];

vector<int> prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(i=2;i<=1e7;i++)
    {
        if(primo[i] == 0)
        {
            prime.push_back(i);
            long long j;
            for(j=1LL*i*i;j<=1e7;j+=i)
            {
                primo[(int) j] = i;
            }
        }
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ori[i] = a[i];
        int div = 0, j=2, cur = 1;
        bool pass = false;
        if(primo[a[i]] != 0){
            int pri = primo[a[i]];
            if(a[i]%pri == 0 && pri<sqrt(ori[i]))
            {
                while(a[i]%pri==0)
                {
                    a[i]/=pri;
                    cur*=pri;
                }
                if(a[i]==1)
                    pass = false;
                else
                    pass = true;
            }
        }
        if(pass)
        {
            b[i] = cur;
            c[i] = a[i];
        }
        else
        {
            b[i] = -1;
            c[i] = -1;
        }
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
    for(i=0;i<n;i++)
        cout<<c[i]<<" ";
}