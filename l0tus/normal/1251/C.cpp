#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        stack<int> A,B;
        for(int i=S.size()-1; i>=0; i--){
            if((S[i]-'0')%2) A.push(S[i]-'0');
            else B.push(S[i]-'0');
        }
        while(A.size()&&B.size()){
            if(A.top()<B.top()){
                cout << A.top();
                A.pop();
            }
            else{
                cout << B.top();
                B.pop();
            }
        }
        while(A.size()){
            cout << A.top();
            A.pop();
        }
        while(B.size()){
            cout << B.top();
            B.pop();
        }
        cout << '\n';
    }
}