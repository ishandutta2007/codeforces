#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    vector<char> lol;
    for (int i=0;i<s.size();i++){
        lol.push_back(s[i]);
        while (lol.size()>1&&lol[lol.size()-1]==lol[lol.size()-2]){
            lol.pop_back();
            lol.pop_back();
        }
    }
    if (lol.empty()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}