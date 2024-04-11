#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int v=0;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if (a<=b-2) v++;
    }
    cout<<v<<endl;
}