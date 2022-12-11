program project1;

var
   a : array[1..1000] of longint;
   id : array[1..1000] of longint;
   i,j,k,n,m,h,sum,normal : longint;
begin
     read(n);
     sum:=0;
     for i:=1 to n do begin
         read(a[i]);
         sum:=sum + a[i];
     end;
     if sum mod n <> 0 then begin
        writeln('Unrecoverable configuration.');
        halt(0);
     end;
     normal:=sum div n;
     h:=0;
     for i:=1 to n do begin
         if a[i] <> normal then begin
            inc(h);
            id[h]:=i;
         end;
     end;
     if h = 0 then begin
        writeln('Exemplary pages.');
        halt(0);
     end;
     if h <> 2 then begin
        writeln('Unrecoverable configuration.');
        halt(0);
     end;
     if a[id[1]] + a[id[2]] = 2 * normal then begin
        if a[id[1]] > a[id[2]] then begin
           k:=id[1];
           id[1]:=id[2];
           id[2]:=k;
        end;
        writeln((a[id[2]] - a[id[1]]) div 2,' ml. from cup #',id[1],' to cup #',id[2],'.');
        halt(0);
     end;
     writeln('Unrecoverable configuration.');
end.