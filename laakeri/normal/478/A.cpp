#include <iostream>

using namespace std;

int main(){
    int s=0;
    for (int i=0;i<5;i++){
        int a;
        cin>>a;
        s+=a;
    }
    if (s==0){
        cout<<-1<<endl;
    }
    else if (s%5==0){
        cout<<s/5<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}