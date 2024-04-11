#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    vector<char> s;
    char a[210000];
    cin >> a;
    int n = strlen(a);
    for(int i = 0; i < n; i++){
        s.push_back(a[i]);
        if(s.size() >= 3){
            if(s[s.size()-1] == s[s.size()-2] && s[s.size()-1] == s[s.size()-3]){
                s.pop_back();
            }
        }
        if(s.size() >= 4){
            if(s[s.size()-1] == s[s.size()-2] && s[s.size()-3] == s[s.size()-4]){
                s.pop_back();
            }           
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}