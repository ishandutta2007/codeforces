# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

char a[200000];
int s[200000];

int main()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    for(int i=1;i<n;i++)
        if(a[i]==a[i+1])s[i]=1;
    for(int i=1;i<=n;i++)
        s[i]+=s[i-1];
    //for(int i=1;i<n;i++)cout<<s[i]<<' ';cout<<endl;
    int m,l,r;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r-1]-s[l-1]);
    } 
    return 0;
}