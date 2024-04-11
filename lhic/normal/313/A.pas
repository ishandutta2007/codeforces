var
  n,min,k:longint;

begin
  readln(n);
  if n>=0 then k:=1 else k:=-1;
  if k=1 then writeln(n)
  else begin
    n:=abs(n);
    min:=n;
    if n div 10<min then min:=n div 10;
    if n mod 10+(n div 100)*10<min then min:=n mod 10+(n div 100)*10;
    writeln(-min)
  end;
end.