#include <iostream>

using namespace std;

int t[100001];
int tt[100001];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    int avf=0;
    int avs=0;
    int avl=0;
    int avn=0;
    for (int i=1;i<n;i++){
        if (t[i]<t[i-1]&&avn==0){
            if (avf){
                cout<<"no"<<endl;
                return 0;
            }
            avf=1;
            avs=i-1;
            avn=1;
        }
        if (t[i]>t[i-1]){
            if (avn){
                avn=0;
                avl=i-1;
            }
        }
    }
    if (avn){
        avl=n-1;
    }
    if (avf){
        for (int i=0;i<n;i++) tt[i]=t[i];
        for (int i=0;i<=avl-avs;i++){
            tt[avs+i]=t[avl-i];
        }
        for (int i=1;i<n;i++){
            if (tt[i]<tt[i-1]){
                cout<<"no"<<endl;
                return 0;
            }
        }
        cout<<"yes"<<endl;
        cout<<avs+1<<" "<<avl+1<<endl;
    }
    else{
        cout<<"yes"<<endl;
        cout<<"1 1"<<endl;
    }
}