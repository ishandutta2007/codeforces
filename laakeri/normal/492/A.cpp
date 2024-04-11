#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int h=0;
    int hh=0;
    int v=0;
    for (int i=1;i<=n;i++){
        hh+=i;
        h+=hh;
        if (h>n) break;
        v=i;
    }
    cout<<v<<endl;
}