#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int query(string s){
  int res;
  printf("%s\n", s.c_str());
  fflush(stdout);
  scanf("%d",&res);
  if(res==0){
    exit(0);
  }
  return res;
}
int main(){
  int i;
  string str;
  int a;
  int b;
  int n;
  int t;
  int x;
  str = "";
  for(i=(0);i<(300);i++){
    str += 'a';
  }
  a = 300 - query(str);
  str = "";
  for(i=(0);i<(300);i++){
    str += 'b';
  }
  b = 300 - query(str);
  n = a + b;
  str = "";
  for(i=(0);i<(n);i++){
    str += 'b';
  }
  if(a==0){
    query(str);
  }
  x = 0;
  for(i=(0);i<(n);i++){
    str[i] = 'a';
    t = query(str);
    if(t==a-x-1){
      x++;
    }
    else{
      str[i] = 'b';
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// int query(string s){
//   int res;
//   printf("%s\n", s.c_str());
//   fflush(stdout);
//   scanf("%d",&res);
//   if(res==0) exit(0);
//   return res;
// }
// 
// {
//   string str;
//   int a, b, n, t, x;
// 
//   str = "";
//   rep(i,300) str += 'a';
//   a = 300 - query(str);
// 
//   str = "";
//   rep(i,300) str += 'b';
//   b = 300 - query(str);
// 
//   n = a + b;
//   str = "";
//   rep(i,n) str += 'b';
//   if(a==0) query(str);
// 
//   x = 0;
//   rep(i,n){
//     str[i] = 'a';
//     t = query(str);
//     if(t==a-x-1) x++; else str[i] = 'b';
//   }
// }