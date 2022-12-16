#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,STOP=17;
int n;
long long a,b,c,k;
long long arr[STOP],matrix[STOP][STOP],help[STOP][STOP],result[STOP][STOP];
void mult_matrix()
{
    memset(result,0,sizeof(result));
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
            for(int p=0;p<STOP;p++)
            result[i][j]=(result[i][j]+matrix[i][p]*help[p][j])%mod;
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
            matrix[i][j]=result[i][j];
}
void mult_help()
{
    memset(result,0,sizeof(result));
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
            for(int p=0;p<STOP;p++)
            result[i][j]=(result[i][j]+help[i][p]*help[p][j])%mod;
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
            help[i][j]=result[i][j];
}

void go(long long st,long long lim)
{
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<STOP;i++)
        matrix[i][i]=1;

    memset(help,0,sizeof(help));
    for(int i=0;i<=lim;i++)help[STOP-1][i]=arr[i];
    for(int i=0;i<=lim;i++)
        for(int j=0;j<=lim;j++)
        if(abs(i-j)<=1)help[i][j]=1;
    /*
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
        {
            if(help[i][j])cout<<i<<" "<<j<<" -> "<<help[i][j]<<endl;
        }
    cout<<endl;
    for(int i=0;i<STOP;i++)
        for(int j=0;j<STOP;j++)
        {
            if(matrix[i][j])cout<<i<<" "<<j<<" -> "<<matrix[i][j]<<endl;
        }
    */
    st++;
    while(st)
    {
        if(st%2==1)mult_matrix();
        mult_help();
        st=st/2;
    }
    for(int i=0;i<STOP;i++)arr[i]=matrix[STOP-1][i];
}
int main()
{
cin>>n>>k;
arr[0]=1;
for(int i=1;i<=n;i++)
{
    cin>>a>>b>>c;
    b=min(b,k);
    go(b-a,c);
}
cout<<arr[0]<<endl;
return 0;
}