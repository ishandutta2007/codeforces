program p1;

var    
    n,m,i,j,a : int64;
begin
    readln(n,m,a);
    i:=n div a;
    j:=m div a;
    if n mod a <> 0 then inc(i);
    if m mod a <> 0 then inc(j);
    writeln(i * j);
end.