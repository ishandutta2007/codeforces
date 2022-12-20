class solve_1690D:

    def __init__(self):
        self.n,self.k=map(int,input().split(' '));
        self.inp=input();

    def solve(self):

        pref=[];

        sum=0;

        for i in range(self.n):
            if self.inp[i]=='W':
                sum=sum+1;

            pref.append(sum);

        mini=self.k;

        for i in range(self.k-1,self.n):
            cur=pref[i];

            if i>=self.k:
                cur=cur-pref[i-self.k];

            mini=min(mini,cur);

        return mini;

t=int(input());

while t:

    t=t-1;

    cur=solve_1690D();

    print(cur.solve());