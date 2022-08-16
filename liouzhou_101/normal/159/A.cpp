#include<iostream>
#include<string>

using namespace std;

const int MaxN=1010;

int n,d;
int pA[MaxN],pB[MaxN],T[MaxN];
int num;
string s[MaxN<<1];
int F[MaxN<<1][MaxN<<1];

int get(string A)
{
    for (int i=1;i<=num;++i)
        if (s[i]==A) return i;
    s[++num]=A;
    return num;
}

int main()
{
    cin>>n>>d;
    for (int i=1;i<=n;++i)
    {
        string A,B;
        cin>>A>>B>>T[i];
        pA[i]=get(A),pB[i]=get(B);
    }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
        {
            if (T[j]-T[i]>d) break;
            if (T[i]!=T[j]&&pA[i]==pB[j]&&pB[i]==pA[j]) F[pA[i]][pB[i]]=F[pB[i]][pA[i]]=1;
        }
    int ans=0;
    for (int i=1;i<=num;++i)
        for (int j=i+1;j<=num;++j)
            if (F[i][j]) ++ans;
    cout<<ans<<endl;
    for (int i=1;i<=num;++i)
        for (int j=i+1;j<=num;++j)
            if (F[i][j]) cout<<s[i]<<" "<<s[j]<<endl;
    return 0;
}