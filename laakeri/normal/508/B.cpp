#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        if ((s[i]-'0')%2==0){
            if (s[n-1]>s[i]){
                swap(s[n-1], s[i]);
                cout<<s<<endl;
                return 0;
            }
        }
    }
    for (int i=n-2;i>=0;i--){
        if ((s[i]-'0')%2==0){
            swap(s[n-1], s[i]);
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}