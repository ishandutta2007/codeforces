#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<char> st;
int cnt;
char s[101010];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(!st.empty() && st.top() == s[i]){
            cnt++;
            st.pop();
        }else st.push(s[i]);
    }
    printf("%s",((cnt%2)?"Yes":"No"));
}