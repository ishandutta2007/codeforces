#include <cstdio>
#include <stack>
using namespace std;

stack<char> pila;

int main(){
	char c;
	while((c=getchar())!=EOF&&c!='\n'){
		if(!pila.empty()&&c==pila.top())pila.pop();
		else pila.push(c);
	}
	puts(pila.empty()?"Yes":"No");
	return 0;
}