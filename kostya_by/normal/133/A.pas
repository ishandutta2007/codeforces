program project1;

var
   st : string;
   i,j,k,n,m : longint;
begin
     read(st);
     for i:=1 to length(st) do if (st[i] = '9') or (st[i] = 'H') or (st[i] = 'Q') then begin
         writeln('YES');
         halt(0);
     end;
     writeln('NO');
end.