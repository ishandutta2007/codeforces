#include<bits/stdc++.h>
using namespace std;
#define ran 333333
int n;
char s1[ran],s2[ran];
char S[ran];
int main(){
	scanf("%s%s",s1,s2);
	n = strlen(s1);
	sort(s1, s1+n);
	sort(s2, s2+n);reverse(s2, s2+n);
	int st2 = 0, en2 = n/2;
	int st1 = 0, en1 = n - en2;
	int s = 0, e = n;
	for(int run=0; run<n; run++){
		if(run % 2 == 0){
			if(st2 < en2 && s1[st1] < s2[st2])
				S[s++] = s1[st1++];
			else
				S[--e] = s1[--en1];
		}else{
			if(st1 < en1 && s2[st2] > s1[st1])
				S[s++] = s2[st2++];
			else
				S[--e] = s2[--en2];
		}
	}
	puts(S);
	return 0;
}