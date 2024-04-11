#include <iostream>
#include <algorithm>
//#include <conio.h>
#include <cmath>
typedef long long int lli;
using namespace std;
//template <class long>
lli* merge(lli *m1, lli* m2, lli l1,lli l2){
    lli* ret = new lli[l1+l2];
    lli n = 0;
   //  ,    
    while (l1 && l2){
        if (*m1 < *m2){
           ret[n] = *m1;
           m1++; l1--;}
        else {
           ret[n] = *m2;
           m2++; l2--;}
       n++;}
    //    
    if (l1 == 0){
        for (lli i=0; i<l2; i++){
            ret[n++] = *m2++;}}
    //    
    else {
        for (lli i=0; i<l1; i++){
           ret[n++] = *m1++;}}
    return ret;}
 
//   
//template <class long>
void mergeSort(lli* mas, lli len){
    lli n=1, l, ost;
    lli * mas1;
    while (n<len){
        l=0;
        while (l<len){
           if (l+n >= len) break;
           ost = (l+n*2>len) ? (len-(l+n)) : n;
           mas1 = merge(mas+l, mas+l+n, n, ost);
           for (lli i=0; i<n+ost; i++) mas[l+i] = mas1[i];
           delete [] mas1;
           l+=n*2;}
       n*=2;
}}   
     
int main ()
 {  lli n,i;

     cin>>n;
    long long a[n];
   double t;
  for (i=0;i<n;i++) cin>>a[i];
  mergeSort(a,n);
  if (n==1 && a[0]==1) cout<<2; else {
  cout<<1;
  for (i=1;i<n-1;i++) cout<<" "<<a[i-1];
  if (n>1) if (a[n-1]==1) cout<<" "<<2; else cout<<" "<<a[n-2]; }
 //   getch();
    return 0;   
         }