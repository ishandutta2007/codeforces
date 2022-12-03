#include <bits/stdc++.h>
using namespace std;

int compare(const void *a,const void *b)
{
    return -*(int*)b+*(int*)a;  
}

int main(){
    int i,j,k,l,m,n,t;
    int a[100000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        for(j=0;j<n;j++) cin>>a[j];
        qsort(a,n,sizeof(int),compare);
        j=0;
        if (a[n-1]==n-1) {
            cout<<k+n<<endl;
        }
        else {
            j=0;
            m=0;
            while(a[j]==m){
                j++;
                m++;
            }
            l=(int)((a[n-1]+m+1)/2);
            while (a[j]<l) j++;
            if ((k!=0)&&(a[j]!=l)) n++;
            cout<<n<<endl;
        }
    }
    return 0;
}