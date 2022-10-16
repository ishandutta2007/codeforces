n = int(raw_input())
print " ".join(str(i+1) for i in range(20,-1,-1) if (n&(1<<i)) > 0)