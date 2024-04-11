#include <iostream>

using namespace std;

int main(){
    int m,s;
    cin>>m>>s;
    if (s==0&&m==1){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    string v1;
    int us=s;
    for (int i=0;i<m;i++){
        int si;
        if (i==0){
            si=1;
        }
        else{
            si=0;
        }
        int c=-1;
        for (int ii=9;ii>=si;ii--){
            if ((us-ii)>=0&&(us-ii)<=9*(m-i-1)){
                c=ii;
            }
        }
        if (c==-1){
            cout<<c<<" ";
            break;
        }
        v1+=(char)(c+'0');
        us-=c;
        if (i==m-1){
            cout<<v1<<" ";
        }
    }
    v1="";
    us=s;
    for (int i=0;i<m;i++){
        int si;
        if (i==0){
            si=1;
        }
        else{
            si=0;
        }
        int c=-1;
        for (int ii=si;ii<=9;ii++){
            if ((us-ii)>=0&&(us-ii)<=9*(m-i-1)){
                c=ii;
            }
        }
        if (c==-1){
            cout<<c;
            break;
        }
        v1+=(char)(c+'0');
        us-=c;
        if (i==m-1){
            cout<<v1;
        }
    }
}