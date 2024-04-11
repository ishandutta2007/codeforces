#include<stdio.h>
#include<stack>
using namespace std;
char x[100005];
stack<char> a;
int main(){
    scanf("%s",x);
    for(int i=0;x[i]!='\0';i++){
        if(a.empty())
        a.push(x[i]);
       else{
            if(a.top()!=x[i]){
            a.push(x[i]);
        }
        else
            a.pop();
   }
   }
    if(a.empty())
    printf("Yes");
    else
    printf("No");
}