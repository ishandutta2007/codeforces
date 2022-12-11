program project1;

var
   c : array[0..31,0..31] of qword;
   n,m,k,i,j,ii,jj : longint;
   ans : qword;
begin
     read(n,m,k);
     c[0,0]:=1;
     for i:=1 to 31 do begin
         for j:=1 to 31 do begin
             c[i,j]:=c[i - 1,j - 1] + c[i - 1, j];
             //write(c[i,j],' ');
         end;
         //writeln;
     end;
     ans:=0;
     for i:=1 to n do begin
         ii:=i;
         jj:=k - i;
         if (ii >= 4) and (jj >= 1) and (ii <= n) and (jj <= m) then begin
            ans:=ans + c[n + 1,ii + 1] * c[m + 1,jj + 1];
            //writeln(ii,' ',jj);
         end;
     end;
     writeln(ans);
end.