#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    int v=0;
    int fp=1e6;
    int lp=0;
    for (int i=0;i<n/2;i++){
        int r=n-i-1;
        v+=min(26-abs(s[i]-s[r]), abs(s[r]-s[i]));
        if (s[i]!=s[r]){
            fp=min(fp, i);
            lp=max(lp, i);
        }
    }
    if (fp==1e6){
        cout<<v<<endl;
    }
    else{
        p--;
        if (p>n/2&&n%2==1){
            p=n/2-(p-n/2);
        }
        if (p>=n/2&&n%2==0){
            p=n/2-(p-n/2+1);
        }
        int d;
        if (p>=lp){
            d=p-fp;
        }
        else if (p<=fp){
            d=lp-p;
        }
        else {
            d=min(2*(p-fp)+(lp-p), 2*(lp-p)+(p-fp));
        }
        cout<<v+d<<endl;
    }
}