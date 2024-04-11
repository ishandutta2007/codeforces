#include <bits/stdc++.h>
using namespace std;

int compare(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;  
}

int main(){
    long long i,j,k,l,m,n,t;
    long long a[100000],b[100000];
    int num[20];
    long double p,q,r;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        k=0;
        for(j=0;j<2*n;j++){
            cin>>l>>m;
            if (l==0) {
                if (m<0) m=-m;
                a[j-k]=m;    //
            }
            else {
                if (l<0) l=-l;
                b[k++]=l;    //
            }
        }
        qsort(a,n,sizeof(long long),compare);
        qsort(b,n,sizeof(long long),compare);
        
        r=0;
        l=0;
        for(j=0;j<20;j++) num[j]=0;
        for(j=0;j<n;j++){
            q=a[j];
            p=b[j];
            r=sqrt(p*p+q*q);
            l+=(long long)r;
            r-=(long long)r;
            for(k=0;k<20;k++) {
                r=r*10;
                num[k]+=(long long)r;
                r=r-(long long)r;
            }
            for(k=19;k>0;k--) {
                if (num[k]>=10){
                    num[k]-=10;
                    num[k-1]++;
                }
            }
            if (num[0]>=10) {
                l++;
                num[0]-=10;
            }
        }
        cout<<l;
        cout<<'.';
        for(j=0;j<20;j++){
            cout<<num[j];
        }
        cout<<endl;
    }
    return 0;
}