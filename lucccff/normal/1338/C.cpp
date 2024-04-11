#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,x,s;
    int a[60];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        x=1;
        l=0;
        while (x<=n) {
            x<<=2;
            l++;
        }
        m=n-(x>>2);
        if (m%3==0) {
            cout<<m/3+(x>>2)<<endl;
        }
        else if (m%3==1) {
            k=0;
            m/=3;
            while(m>0) {
                if ((m&3)==0) {
                    a[k++]=0;
                }
                else if ((m&3)==1) {
                    a[k++]=2;
                }
                else if ((m&3)==2) {
                    a[k++]=3;
                }
                else if ((m&3)==3) {
                    a[k++]=1;
                }
                m>>=2;
            }
            l=0;
            for(j=k-1;j>=0;j--) l=(l<<2)+a[j];
            cout<<l+(x>>1)<<endl;
        }
        else {
            k=0;
            m/=3;
            while(m>0) {
                if ((m&3)==0) {
                    a[k++]=0;
                }
                else if ((m&3)==1) {
                    a[k++]=3;
                }
                else if ((m&3)==2) {
                    a[k++]=1;
                }
                else if ((m&3)==3) {
                    a[k++]=2;
                }
                m>>=2;
            }
            l=0;
            for(j=k-1;j>=0;j--) {
                l=(l<<2)+a[j];
            }
            cout<<l+(x>>1)+(x>>2)<<endl;
        }
    }
    return 0;
}