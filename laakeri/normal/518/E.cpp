#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[100001];
int lol[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        int neg=0;
        if (s[0]=='-') neg=1;
        if (s[0]=='?') lol[i]=1;
        else{
            int v=0;
            for (int ii=neg;ii<s.size();ii++){
                v*=10;
                v+=s[ii]-'0';
            }
            if (neg) v=-v;
            a[i]=v;
        }
    }
    for (int b=0;b<k;b++){
        int miv=-2e9;
        int ak=-1;
        int h=0;
        for (int i=b;i<n;i+=k){
            if (lol[i]){
                if (ak==-1) ak=i;
                h++;
            }
            else{
                int mav=a[i]-1;
                if (h>0){
                    if (miv<0){
                        if (miv<=-(h/2)){
                            if (-(h/2)+h-1<=mav){
                                int v=-(h/2);
                                for (int ii=ak;ii<i;ii+=k){
                                    a[ii]=v++;
                                }
                            }
                            else{
                                int v=mav-h+1;
                                for (int ii=ak;ii<i;ii+=k){
                                    a[ii]=v++;
                                }
                            }
                        }
                        else{
                            int v=miv;
                            for (int ii=ak;ii<i;ii+=k){
                                a[ii]=v++;
                            }
                        }
                    }
                    else {
                        int v=miv;
                        for (int ii=ak;ii<i;ii+=k){
                            a[ii]=v++;
                        }
                    }
                }
                ak=-1;
                h=0;
                miv=a[i]+1;
            }
        }
        if (h>0){
            if (miv<0){
                if (miv<=-(h/2)){
                    int v=-(h/2);
                    for (int ii=ak;ii<n;ii+=k){
                        a[ii]=v++;
                    }
                }
                else{
                    int v=miv;
                    for (int ii=ak;ii<n;ii+=k){
                        a[ii]=v++;
                    }
                }
            }
            else{
                int v=miv;
                for (int ii=ak;ii<n;ii+=k){
                    a[ii]=v++;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (i+k<n&&a[i+k]<=a[i]){
            cout<<"Incorrect sequence"<<endl;
            return 0;
        }
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}