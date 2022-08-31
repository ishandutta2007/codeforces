#include<iostream>
#include<string>
using namespace std;

int main(){
int n;
cin >> n;
string k[n];
string S;
S += "<3";
for(int i = 0; i < n; i++){
    cin >> k[i];
    S += k[i];
    S += "<3";

}
string R;
cin >> R;
int cur=  0;
for(int i = 0; i < R.size(); i++){
    if(cur == S.size()) break;
    if(S[cur] == R[i]) cur++;
}
if(cur == S.size()){
    cout << "yes" << endl;
} else {
    cout << "no" << endl;
}
}