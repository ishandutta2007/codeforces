s=raw_input()
p=sum(s.count(x)%2 for x in set(s))
print'First'if p&1 or p==0 else'Second'