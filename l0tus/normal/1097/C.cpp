#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int MN =1e5+5;
vector<int> X,Y;
string S;
stack<char> st;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,cnt=0;
    cin >> N;
    for(int j=0; j<N; j++){
        S.clear();
        cin >> S;
        int len = S.size();
        for(int i=0; i<len; i++){
            if(!st.empty() && S[i]==')' && st.top()=='(') st.pop();
            else st.push(S[i]);
        }
        int a=0,b=0;
        while(!st.empty()){
            if(st.top()=='(') a++;
            else b++;
            st.pop();
        }
        if(!a && !b)
        {
            cnt++;
            continue;
        }
        if(a && b) continue;
        if(a) X.push_back(a);
        else if(b) Y.push_back(b);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    //cout << X.size();
    int sa=0,sb=0,ans=0;
    //cout << ans;
    while(sa<X.size() && sb<Y.size()){
        if(X[sa]==Y[sb]){
            ans++;
            sa++;
            sb++;
        }
        else if(X[sa]>Y[sb]) sb++;
        else sa++;
    }
    //cout << ans;
    int x = cnt/2;
    cout << ans+x;
}