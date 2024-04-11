#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> lol,asd,qaq;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a==1) lol.push_back(i+1);
        if (a==2) asd.push_back(i+1);
        if (a==3) qaq.push_back(i+1);
    }
    int a=min(lol.size(), min(asd.size(), qaq.size()));
    cout<<a<<endl;
    for (int i=0;i<a;i++){
        cout<<lol[i]<<" "<<asd[i]<<" "<<qaq[i]<<endl;
    }
}