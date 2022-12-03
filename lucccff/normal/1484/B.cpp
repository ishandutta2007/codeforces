#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[100000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        if (n<3) cout<<0<<endl;
        else {
            k=0;
            while((k<n-1)&&(a[k]>=a[k+1])) k++;
            if (k==n-1) {
                int f=0;
                l=a[0]-a[1];
                for(j=1;j<n-1;j++) {
                    if (a[j]-a[j+1]!=l) {
                        f=1;
                        break;
                    }
                }
                if (f==1) cout<<-1<<endl;
                else cout<<0<<endl;
            }
            else {
                l=a[k+1]-a[k];
                k=0;
                while((k<n-1)&&(a[k]<a[k+1])) k++;
                if (k==n-1) {
                    int f=0;
                    for(j=1;j<n-1;j++) {
                        if (a[j+1]-a[j]!=l) {
                            f=1;
                            break;
                        }
                    }
                    if (f==1) cout<<-1<<endl;
                    else cout<<0<<endl;
                }
                else {
                    m=a[k+1]-a[k];
                    int min1=1000000001,min2=1000000001,max1=-1,max2=-1;
                    int min=1000000001,max=-1;
                    int f=0;
                    for(j=0;j<n-1;j++) {
                        if (a[j+1]-a[j]>0) {
                            if (a[j]>max1) max1=a[j];
                            if (a[j+1]<min1) min1=a[j+1];
                            if (a[j+1]-a[j]!=l) {
                                f=1;
                                break;
                            }
                        }
                        else {
                            if (a[j+1]>max2) max2=a[j+1];
                            if (a[j]<min2) min2=a[j];
                            if (a[j+1]-a[j]!=m) {
                                f=1;
                                break;
                            }
                        }
                        if (a[j]>=-m+l) {
                            f=1;
                            break;
                        }
                    }
                    if (a[n-1]>-m+l) f=1;
                    if (f==1) cout<<-1<<endl;
                    else if (max1>=min2) cout<<-1<<endl;
                    else if (max2>=min1) cout<<-1<<endl;
                    else cout<<-m+l<<' '<<l<<endl;
                }
            }
        }
    }
    return 0;
}