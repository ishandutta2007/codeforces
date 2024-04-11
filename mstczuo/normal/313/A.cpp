# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

char a[100];
int main()
{
    scanf("%s",a);
    if(a[0]!='-'){
        printf("%s\n",a);
        return 0;
    }
    int t=1,k=0,n=strlen(a);
    if(a[n-1]>a[n-2]){
        a[n-1]=0;
    }else{
        a[n-2]=a[n-1];
        a[n-1]=0;
    }
    sscanf(a,"%d",&k);
    cout<<k<<endl;
    return 0;
}