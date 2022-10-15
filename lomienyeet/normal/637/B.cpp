#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    stack<string> st;
    set<string> seen;
    for(int i=0;i<N;i++){
        string a;
        cin>>a;
        st.push(a);
    }
    while(!st.empty()){
        if(!seen.count(st.top())){
            cout<<st.top()<<"\n";
            seen.insert(st.top());
        }
        st.pop();
    }
    return 0;
}