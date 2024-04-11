#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
const int N = 200010;
char str[N];
int n, ans[N], dep = 0;
stack<char> s;
int main(){
    scanf("%d%s", &n, str + 1);
    for(int i = 1; i <= n; i++){
        if(str[i] == '('){
            ans[i] = (++dep) & 1;
            s.push('(');
        }else if(str[i] == ')'){
            ans[i] = (dep--) & 1;
            s.pop();
        }
    }
    for(int i = 1 ;i <= n; i++) 
        printf("%d", ans[i]);
    return 0;
}