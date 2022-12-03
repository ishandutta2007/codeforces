#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,h,f=0,x,y;
    string time;
    int a[25]={0,1,2,5,8,10,11,12,15,18,20,21,22,25,28,50,51,52,55,58,80,81,82,85,88};
    cin>>t;
    for(i=0;i<t;i++){
        cin>>h>>m;
        cin>>time;
        k=(int)(time[0]-'0')*10+(int)(time[1]-'0');
        l=(int)(time[3]-'0')*10+(int)(time[4]-'0');
        f=0;
        while(f==0){
            for(j=0;j<25;j++) {
                if (a[j]==k) f++;
                if (a[j]==l) f++;
            }
            if (f<2) f=0;
            else {
                x=(int)(k/10);  
                y=k%10;
                if (x==2) x=5;
                else if (x==5) x=2;
                if (y==2) y=5;
                else if (y==5) y=2;
                if (x+y*10>=m) f=0;
                x=(int)(l/10);
                y=l%10;
                if (x==2) x=5;
                else if (x==5) x=2;
                if (y==2) y=5;
                else if (y==5) y=2;
                if (x+y*10>=h) f=0;
            }
            if (f==0) {
                l++;
                if (l==m) {
                    l=0;
                    k++;
                }
                if (k==h) {
                    k=0;
                    f=1;
                }
            }
        }
        cout<<(int)(k/10)<<k%10<<':'<<(int)(l/10)<<l%10<<endl;
    }
    return 0;
}