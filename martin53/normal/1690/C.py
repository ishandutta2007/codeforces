class solve_1690C:

    def __init__(self):
        self.n=int(input());
        self.s=list(map(int,input().split(' ')));
        self.f=list(map(int,input().split(' ')));

    def solve(self):

        print(self.f[0]-self.s[0],end=' ');

        for i in range(1,self.n):
            print(self.f[i]-max(self.f[i-1],self.s[i]),end=' ');

        print();


t=int(input());

while t:
    t=t-1;

    cur=solve_1690C();

    cur.solve();