var n,i,j,t:integer;
begin
 readln(n);
 for i:=1 to 2*n+1 do begin

  for j:=1 to abs(n+1-i) do begin
   write('  ');  end;
  t:=2*n-abs(2*n-2*i+2);
  for j:=0 to t-1 do
   write(t div 2-abs(t div 2-j),' ');
   write('0');
   writeln;
  end;


end.