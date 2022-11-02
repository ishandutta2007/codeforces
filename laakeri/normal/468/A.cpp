#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    if (n<4){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        int s5=0;
        int s1=1;
        for (int i=n;i>=5;i-=2){
            if (i>5) {
                s1++;
                cout<<i<<" - "<<i-1<<" = "<<1<<'\n';
            }
            else {
                s5=1;
            }
        }
        if (s5){
            cout<<"5 * 4 = 20"<<endl;
            cout<<"20 + 3 = 23"<<endl;
            cout<<"23 + 2 = 25"<<endl;
            cout<<"25 - 1 = 24"<<endl;
            s1--;
        }
        else{
            cout<<"4 * 3 = 12"<<endl;
            cout<<"12 * 2 = 24"<<endl;
        }
        for (int i=0;i<s1;i++){
            cout<<"24 * 1 = 24"<<'\n';
        }
    }
}