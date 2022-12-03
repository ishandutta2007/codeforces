#include<bits/stdc++.h>
const int N = 2e2 + 10;
int ri() {
    char ch = getchar(); int x = 0, f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}
int addx, subx, addy, suby;
int main() {
    for(int T = ri();T--;) {
        int n = ri(), m = ri();
        int d1, d2, d3, d4;
        std::cout<<"SCAN 1 1\n"<<std::flush;
        std::cin>>d1;
        std::cout<<"SCAN 1 "<<m<<'\n'<<std::flush;
        std::cin>>d2;
        addy = ((d1 - d2) >> 1) + m + 1;
        addx = d1 + 4 - addy;
        int z = addx >> 1;
        std::cout<<"SCAN "<<z<<" 1\n"<<std::flush;
        std::cin>>d3;
        subx = 2 - addy + d3;
        z = addy >> 1;
        std::cout<<"SCAN 1 "<<z<<'\n'<<std::flush;
        std::cin>>d4;
        suby = 2 - addx + d4;
        int X2 = (subx + addx >> 1), X1 = (addx - subx >> 1);
        int Y2 = (suby + addy >> 1), Y1 = (addy - suby >> 1);
        std::cout<<"DIG "<<X1<<" "<<Y1<<'\n'<<std::flush;
        bool p;
        std::cin>>p;
        if(p) {
            std::cout<<"DIG "<<X2<<" "<<Y2<<'\n'<<std::flush;
            std::cin>>p;
        }
        else {
           std::cout<<"DIG "<<X1<<" "<<Y2<<'\n'<<std::flush; 
           std::cin>>p;
           std::cout<<"DIG "<<X2<<" "<<Y1<<'\n'<<std::flush;
           std::cin>>p;
        }
    }
    return 0;
}