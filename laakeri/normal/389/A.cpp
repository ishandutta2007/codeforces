#include <iostream>
#include <vector>

using namespace std;

int ns[100];

int main(){
    int n;
    cin>>n;
    int i;
    int mi=999999;
    for (i=0;i<n;i++){
        cin>>ns[i];
        mi=min(mi,ns[i]);
    }
    int f=1;
    while (f){
        f=0;
        for (i=0;i<n;i++){
            if (ns[i]>mi){
                f=1;
                ns[i]-=mi;
                mi=min(ns[i],mi);
            }
        }
    }
    int su=0;
    for (i=0;i<n;i++){
        su+=ns[i];
    }
    cout<<su<<endl;
}