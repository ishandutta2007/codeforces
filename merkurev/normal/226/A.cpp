#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


#define Matr pair <pair<long long,long long>,pair<long long,long long>>

Matr multiply (Matr A,Matr B,long long m)
{
    Matr P;
    P.first.first = ( A.first.first * B.first.first + A.first.second * B.second.first ) % m;
    P.first.second = ( A.first.first * B.first.second + A.first.second * B.second.second ) % m;
    P.second.first = ( A.second.first * B.first.first + A.second.second * B.second.first ) % m;
    P.second.second = ( A.second.second * B.first.second + A.second.second * B.second.second ) % m;


    return P;
}

Matr ONE(long long m)
{
    Matr P;
    P.first.first = 1 % m;
    P.first.second = 0 % m;
    P.second.first = 0 % m;
    P.second.second = 1 % m;

    return P;
}

Matr fpow(Matr M,long long n,long long m)
{
    if (!n)
        return ONE(m);
    Matr a = fpow(M,n>>1,m);
    a=multiply(a,a,m);
    
    if (n&1)
        a=multiply(a,M,m);
    return a;
}

void main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    long long n,m;
    scanf("%I64d%I64d",&n,&m);


        Matr M = make_pair(make_pair(3,0),make_pair(1,1));
        M = fpow(M,n,m);

        printf("%I64d\n",(M.second.first * 2)%m);


}