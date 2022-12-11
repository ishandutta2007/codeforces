program project1;

var
   st, five, int, drob : ansistring;
   i,j,k,n,m : longint;
begin
     read(st);
     for i:=1 to length(st) do begin
         if st[i] = '.' then break;
     end;
     int:=copy(st,1,i - 1);
     delete(st,1,i);
     drob:=st;
     five:='5';
     while length(five) < length(drob) do five:=five + '0';
     if int[length(int)] = '9' then begin
        writeln('GOTO Vasilisa.');
        halt(0);
     end;
     if drob < five then begin
        writeln(int);
        halt(0);
     end;
     int[length(int)]:=chr(ord(int[length(int)]) + 1);
     writeln(int);
end.