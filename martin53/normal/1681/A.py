class solver_1681A:

    def __init__(self):
        self.n=int(input());
        self.a=list(map(int,input().split(' ')));
        self.m=int(input());
        self.b=list(map(int,input().split(' ')));

    def solve(self):

        if max(self.a)>=max(self.b):
            print("Alice");
        else:
            print("Bob");

        if max(self.a)<=max(self.b):
            print("Bob");
        else:
            print("Alice");


t=int(input());

while t:
    t=t-1;

    cur=solver_1681A();

    cur.solve();