#include <bits/stdc++.h>
using namespace std;
main()
{
    int a,ta,b,tb,hh,mm;
    cin>>a>>ta>>b>>tb;
    scanf("%d:%d",&hh,&mm);
    int start = hh*60+mm-300-tb;
    int finish = hh*60+mm-300+ta;
    if (start < 0) {start = 0;} else {start = (start / b) * b + b;}
    if (finish > 1139) {finish = (1139 / b) * b;} else {finish = (finish / b) * b - b * (finish % b == 0);}
    cout<<(finish-start)/b + 1;
}