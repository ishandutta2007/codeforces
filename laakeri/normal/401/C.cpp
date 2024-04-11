#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

typedef long long ll;

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    if (n>m){
        if (n>m+1){
            cout <<"-1"<<endl;
            return 0;
        }
        else{
            for (int i=0;i<n+m;i++){
                if (i%2==0){
                    cout <<'0';
                }
                else{
                    cout <<'1';
                }
            }
        }
    }
    else if (n==m){
        for (int i=0;i<n+m;i++){
            if (i%2==0){
                cout <<'0';
            }
            else{
                cout <<'1';
            }
        }
    }
    else{
        m-=2;
        int rat=m/n;
        if (m%n){
            rat++;
        }
        if (rat>2){
            cout <<"-1"<<endl;
        }
        else{
            cout <<'1'<<'1';
            for (;n>0;){
                cout <<'0';
                n--;
                for (int i=0;i<min(rat,m);i++){
                    cout <<'1';
                }
                m-=rat;
                if (n==0){
                    rat=m;
                }
                else{
                    rat=m/n;
                    if (m%n){
                        rat++;
                    }
                }
            }
        }
    }
    cout <<endl;
}