#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    if(n>m)swap(n,m);
    if(n==1){
        ///Easy construction for n==1
        if(m%6==0)printf("%d\n",m);
        else if(m%6>=4)printf("%d\n",m-(6-(m%6)));
        else printf("%d\n",m-(m%6));
    }
    else if(n==2){
        ///This one is harder
        ///notice that you can construct 2*4,2*5,2*6
        ///Amazingly, do you believe that
        ///every number >7 can be written if form 4*x+5*y+6*z
        ///bash 4 cases if a%4==1 minus 5 if a%4==2 minus 6 if a%4==3 minus 11
        if(m==3||m==7)printf("%d\n",(m-1)<<1);
        else if(m<=2)printf("%d\n",0);
        else printf("%d\n",m<<1);
    }
    else{
        ///This part is the most interesting
        ///notice that you can construct 4*x 6*x when x>=2
        ///so if n*m is even you can always construct it!
        ///But how? Of course we can always construct
        ///V*x when V is even number by easy fact like
        /// every even number>=4 can be written in form of 4*x+6*y
        ///so just print if n*m is even!
        if(!(n&1&&m&1))
        printf("%lld\n",1LL*n*m);
        /// but when n*m? is even
        /// This one is quite hard but you can notice that you can construct
        /// few one like 3*3 3*5 and 5*5 with just one place left
        /// ok you can always reduce to these 3 by 4*x and 6*x!
        /// of course by minus 4 and 6 it can be reduce in form of 5*(odd) and 3*odd
        /// since you can construct 3*4 you can always reduce to 3*3 or 3*5!
        /// and you can always construct 2*5 so just reduce it to 5*5!
        /// Construction is done! Normally I don't like tiling and bashing problem
        /// But this one is really cool! I'm very fun while doing construction
        /// wonder how many people write full construction during contest
        /// It's very cool problem!
        else
        printf("%lld\n",1LL*n*m-1);
    }

}