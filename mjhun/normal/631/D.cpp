#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
#define PTYPE pair<char,ll>
using namespace std;

typedef long long ll;

int n,m;
int F[200005];
PTYPE s[200005];
PTYPE t[200005];
vector<int> v;

void build_failure_function(PTYPE pattern[])
{
  // let m be the length of the pattern 
  F[0] = F[1] = 0; // always true
  
  for(int i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    int j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
}

void kmp(PTYPE text[], PTYPE pattern[])
{
  // let n be the size of the text, m the 
  // size of the pattern, and F[] - the
  // "failure function"
//  for(int i=0;i<n;++i)putchar(text[i].fst);puts("");
//  for(int i=0;i<m;++i)putchar(pattern[i].fst);puts("");
//  for(int i=0;i<=m;++i)printf("  %d",F[i]);puts("");
  build_failure_function(pattern); 

  int i = 0; // the initial state of the automaton is
         // the empty string

  int j = 0; // the first character of the text
  
  for( ; ; ) {
//  	printf("   %d %d\n",i,j);
    if(j == n) break; // we reached the end of the text

    // if the current character of the text "expands" the
    // current match 
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m){ // match found
        
        v.push_back(j-m);//printf(" %d\n",j-m);
        i = F[i];
      }
    }

    // if the current state is not zero (we have not
    // reached the empty string yet) we try to
    // "expand" the next best (largest) match
    else if(i > 0) i = F[i];

    // if we reached the empty string and failed to
    // "expand" even it; we go to the next 
    // character from the text, the state of the
    // automaton remains zero
    else j++;
  }
}

int n0,m0;

int main(){
	scanf("%d%d",&n0,&m0);
	for(int i=0;i<n0;++i){
		int l;char c;
		scanf("%d-%c",&l,&c);//printf("%d-%c\n",l,c);
		if(i>0&&c==s[i-1].fst){
			s[i-1].snd+=l;
			i--;n0--;
		}
		else {
			s[i]=mp(c,l);
		}
	}
	for(int i=0;i<m0;++i){
		int l;char c;
		scanf("%d-%c",&l,&c);//printf("%d-%c\n",l,c);
		if(i>0&&c==t[i-1].fst){
			t[i-1].snd+=l;
			i--;m0--;
		}
		else {
			t[i]=mp(c,l);
		}
	}//printf("%d %d\n",n0,m0);
	ll r=0;
	if(n0>=m0){
		if(m0==1){
			for(int i=0;i<n0;++i){
				if(s[i].fst==t[0].fst)r+=max(s[i].snd-t[0].snd+1,0LL);
			}
		}
		else if(m0==2){
			for(int i=0;i<n0-1;++i){
				if(s[i].fst==t[0].fst && s[i+1].fst==t[1].fst && s[i].snd>=t[0].snd && s[i+1].snd>=t[1].snd)r++;
			}
		}
		else {
			n=n0-2;
			m=m0-2;
			kmp(s+1,t+1);
			for(int i=0;i<v.size();++i){
				int k=v[i];
				if(s[k].fst==t[0].fst && s[k+m0-1].fst==t[m0-1].fst && s[k].snd>=t[0].snd && s[k+m0-1].snd>=t[m0-1].snd)r++;
			}
		}
	}
	cout<<r<<endl;
	return 0;
}