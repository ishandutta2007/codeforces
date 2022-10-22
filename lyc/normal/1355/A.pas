uses math;
var t,i,x,y,j:longint;st:ansistring;p,k:qword;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(p,k);
    str(p,st); dec(k);
    while (pos('0',st)=0)and(k<>0) do
    begin
      x:=-1;y:=100;
      for j:=1 to length(st) do
      begin
        x:=max(x,ord(st[j])-ord('0'));
        y:=min(y,ord(st[j])-ord('0'));
      end;
      p:=p+x*y;
      str(p,st);
      dec(k);
    end;
    writeln(st);
  end;
end.