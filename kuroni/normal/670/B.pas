var n, k, i: longint;
    ID : array[1..100000] of longint;
begin
    read(n,k);
    for i:=1 to n do read(ID[i]);
    i:=round(sqrt(2)*sqrt(k));
    write(ID[k - ((i*(i-1)) div 2)]);
end.